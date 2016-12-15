'use strict';

const assert = require('assert');
const Struct = require('../cpp').Struct;

const Type = require('./_type.js');
const Structure = require('./_structure.js');
const DefaultValue = require('./_default.js');

class Dictionary extends Structure {
  constructor(content) {
    assert.equal(content.type, 'dictionary');
    const struct = new Struct(content.name, content.inheritance);

    for (const member of content.members) {
      assert.equal(member.type, 'field');
      struct.addField({
        name: member.name,
        type: new Type(member.idlType),
        required: member.required,
        defaultValue: new DefaultValue(member.default)
      });
    }

    super(struct);
  }
}

module.exports = Dictionary;
