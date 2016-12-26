'use strict';

const Type = require('./_type.js');
const DefaultValue = require('./_default.js');

const name_map = {
  'namespace': 'ns'
};

class Argument {
  constructor(arg, include, direct = false) {
    if (direct) {
      this.name = arg.name;
      this.optional = arg.optional;
      this.type = arg.type;
      this.defaultValue = arg.defaultValue;
      this.include = include;
    } else {
      this.name = arg.name;
      if (name_map.hasOwnProperty(this.name)) {
        this.name = name_map[this.name];
      }

      this.optional = arg.optional;
      this.type = new Type(arg.idlType, include);
      this.defaultValue = new DefaultValue(arg.default);

      this.include = include;
    }
  }

  *[Symbol.iterator]() {
    for (const type of this.type) {
      yield new Argument({
        name: this.name,
        optional: this.optional,
        type: type,
        defaultValue: this.defaultValue
      }, this.include, true);
    }
  }

  toString() {
    let str = 'const ';

    if (this.optional) {
      str += `optional<${this.type}>`;
    } else {
      str += this.type.toString();
    }

    str += ` ${this.name}`;

    if (this.defaultValue.exists) {
      str += ` = ${this.defaultValue}`;
    }

    return str;
  }
}

module.exports = Argument;
