'use strict';

class Include {
  constructor(name) {
    this.name = name;
    this.include = new Map();
  }

  addDependency({name, format=true}) {
    if (name && name !== this.name) {
      this.include.set(name, format);
    }
  }

  header() {
    let str = '';

    for (const [name, format] of this.include) {
      str += `#include "${format ? name.toLowerCase() : name}.hpp"\n`;
    }

    return str;
  }

  body() {
    return '';
  }
}

module.exports = Include;
