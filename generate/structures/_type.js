'use strict';

const assert = require('assert');

const WebIDL_TO_CPP = {
  'boolean': 'bool',
  'DOMString': 'std::string',
  'USVString': 'std::string',
  'DOMTimeStamp': 'long int'
}

class Type {
  constructor(idlType) {
    assert.ok(idlType.idlType);

    this.sequence = !!idlType.sequence;
    this.generic = idlType.generic || null;
    this.nullable = !!idlType.nullable;
    this.array = !!idlType.array;
    this.union = !!idlType.union;

    if (this.union) {
      this.type = idlType.idlType.map((item) => new Type(item));
    } else if (typeof idlType.idlType === 'object') {
      this.type = new Type(idlType.idlType);
    } else {
      this.type = idlType.idlType;
    }
  }

  toString() {
    if (this.union) {
      return `union<${this.type.join(', ')}>`;
    }

    let type = this.type.toString();
    if (WebIDL_TO_CPP.hasOwnProperty(this.type)) {
      type = WebIDL_TO_CPP[this.type];
    }

    if (this.nullable) {
      type = `optional<${type}>`;
    }

    if (this.sequence) {
      type = `std::vector<${type}>`
    }

    return type;
  }
}

module.exports = Type;
