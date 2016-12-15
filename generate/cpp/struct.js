'use strict';

class Struct {
  constructor(name, inheritance) {
    this.name = name;
    this.inheritance = inheritance;
    this.fields = new Map();
  }

  addField({name, type, required, defaultValue}) {
    this.fields.set(name, {type, required, defaultValue});
  }

  header() {
    let inheritance = '';
    if (this.inheritance !== null) inheritance = ` : ${this.inheritance}`;
    let str = `struct ${this.name}${inheritance} {\n`;

    for (const [name, descriptor] of this.fields) {
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
