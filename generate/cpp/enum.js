'use strict';

class Enum {
  constructor(name) {
    this.name = name;
    this.values = [];
  }

  addValue({value}) {
    this.values.push(value);
  }

  header() {
    return `enum ${this.name} { ${this.values.join(', ')} };\n`;
  }

  body() {
    return this.header();
  }
}

module.exports = Enum;
