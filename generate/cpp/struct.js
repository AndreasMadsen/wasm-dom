'use strict';

class Struct {
  constructor(name) {
    this.name = name;
    this.fields = new Map();
  }

  addField({name, type, required, defaultValue}) {
    this.fields.set(name, {type, required, defaultValue});
  }

  header() {
    let str = `struct ${this.name} {\n`;

    for (const [name, descriptor] of this.fields) {
      console.log(descriptor.type);
      if (descriptor.defaultValue.exists) {
        str += `  ${descriptor.type} ${name} = ${descriptor.defaultValue};\n`;
      } else {
        str += `  ${descriptor.type} ${name};\n`;
      }
    }

    return str + '};\n';
  }

  body() {
    return this.header();
  }
}

module.exports = Struct;
