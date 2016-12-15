'use strict';

const assert = require('assert');
const Class = require('../cpp').Class;

const Type = require('./_type.js');
const Structure = require('./_structure.js');
const DefaultValue = require('./_default.js');
const Value = require('./_value.js');

class Interface extends Structure {
  constructor(content) {
    assert.equal(content.type, 'interface');
    const cls = new Class(content.name, content.inheritance);

    for (const member of content.members) {
      if (member.type === 'attribute') {
        cls.addAttribute({
          name: member.name,
          type: new Type(member.idlType),
          readonly: member.readonly,
          defaultValue: new DefaultValue(member.default)
        });
      } else if (member.type === 'operation') {
        // TODO: an operator without a name?
        if (member.name) {
          cls.addMethod({
            name: member.name,
            type: new Type(member),
            args: (member.arguments || []).map((arg) => ({
              name: arg.name,
              optional: arg.optional,
              type: new Type(arg.idlType),
              defaultValue: new DefaultValue(arg.default)
            }))
          });
        }
      } else if (member.type === 'const') {
        assert.equal(member.nullable, false);
        cls.addConst({
          name: member.name,
          type: new Type(member),
          value: new Value(member.value)
        })
      } else if (member.type === 'iterable') {
        // TODO: what is an iterable member?
      } else {
        throw new TypeError(`unsupported member type ${member.type}`);
      }
    }

    super(cls);
  }
}

module.exports = Interface;
