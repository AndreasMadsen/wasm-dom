'use strict';

const Type = require('./_type.js');
const DefaultValue = require('./_default.js');

const name_map = {
  'namespace': 'ns'
};

class Argument {
  constructor(arg, include) {
    this.name = arg.name;
    if (name_map.hasOwnProperty(this.name)) {
      this.name = name_map[this.name];
    }

    this.optional = arg.optional;
    this.type = new Type(arg.idlType, include);
    this.defaultValue = new DefaultValue(arg.default);
  }

  toString() {
    let str = 'const ';

    if (this.optional) {
      str += `optional<${this.type}>`;
    } else {
      str += this.type;
    }

    str += ` ${this.name}`;

    if (this.defaultValue.exists) {
      str += ` = ${this.defaultValue}`;
    }

    return str;
  }
}

module.exports = Argument;
