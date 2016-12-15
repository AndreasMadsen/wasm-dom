'use strict';

class Class {
  constructor(name, inheritance) {
    this.name = name;
    this.inheritance = inheritance;
    this.attributes = new Map();
    this.methods = new Map();
    this.consts = new Map();
  }

  addConst({name, type, value}) {
    this.consts.set(name, {type, value});
  }

  addAttribute({name, type, readonly, defaultValue}) {
    this.attributes.set(name, {type, readonly, defaultValue});
  }

  addMethod({name, type, args}) {
    this.methods.set(name, {type, args});
  }

  header() {
    let inheritance = '';
    if (this.inheritance !== null) inheritance = ` : ${this.inheritance}`;
    let str = `class ${this.name}${inheritance} {\n`;

    // Add static const
    if (this.consts.size > 0) str += '  // constants\n';
    for (const [name, descriptor] of this.consts) {
      str += `  static const ${descriptor.type} ${name} = ${descriptor.value};\n`;
    }
    if (this.consts.size > 0 && (this.attributes.size > 0 || this.methods.size > 0)) {
      str += '\n';
    }

    // Add attributes
    if (this.attributes.size > 0) str += '  // attributes\n';
    for (const [name, descriptor] of this.attributes) {
      str += `  ${descriptor.type} get_${name}() const;\n`;

      if (!descriptor.readonly) {
        str += `  ${descriptor.type} set_${name}(const ${descriptor.type} ${name});\n`;
      }
    }
    if (this.attributes.size > 0 && this.methods.size > 0) {
      str += '\n';
    }

    // Add methods
    if (this.methods.size > 0) str += '  // methods\n';
    for (const [name, descriptor] of this.methods) {
      str += `  const ${descriptor.type} ${name}(`
      str += descriptor.args.join(', ');
      str += `);\n`;
    }

    return str + '};\n';
  }

  body() {
    return this.header();
  }
}

module.exports = Class;
