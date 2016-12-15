'use strict';

const assert = require('assert');
const Enum = require('../cpp').Enum;

const Structure = require('./_structure.js');

class Dictionary extends Structure {
  constructor(content) {
    assert.equal(content.type, 'enum');
    const enums = new Enum(content.name);

    for (const value of content.values) {
      enums.addValue({ value });
    }

    super(enums);
  }
}

module.exports = Dictionary;
