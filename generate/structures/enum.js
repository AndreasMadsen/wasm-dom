'use strict';

const assert = require('assert');
const CppEnum = require('../cpp').Enum;
const Include = require('../cpp').Include;

const Structure = require('./_structure.js');

class Enum extends Structure {
  constructor(content) {
    assert.equal(content.type, 'enum');
    const enums = new CppEnum(content.name);
    const include = new Include(content.name);

    for (const value of content.values) {
      enums.addValue({ value });
    }

    super(content.name, enums, include);
  }
}

module.exports = Enum;
