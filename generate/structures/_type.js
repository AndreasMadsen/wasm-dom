'use strict';

const WebIDL_TO_CPP = {
  'boolean': 'bool',
  'DOMString': 'std::string',
  'USVString': 'std::string'
}

class Type {
  constructor(idlType) {
    this.sequence = idlType.sequence;
    this.generic = idlType.generic;
    this.nullable = idlType.nullable;
    this.array = idlType.array;
    this.union = idlType.union;

    if (typeof idlType.idlType === 'object' && idlType.idlType !== null) {
      this.type = new Type(idlType.idlType);
    } else {
      this.type = idlType.idlType;
    }
  }

  toString() {
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
