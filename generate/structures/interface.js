'use strict';

const assert = require('assert');
const Class = require('../cpp').Class;
const Include = require('../cpp').Include;

const Type = require('./_type.js');
const ArgumentList = require('./_argument_list.js');
const Structure = require('./_structure.js');
const DefaultValue = require('./_default.js');
const Value = require('./_value.js');

class Interface extends Structure {
  constructor(content) {
    assert.ok(['interface', 'callback interface'].includes(content.type));

    const cls = new Class(content.name, content.inheritance);
    const include = new Include(content.name);
    include.addDependency({name: content.inheritance});

    for (const member of content.members) {
      if (member.type === 'attribute') {
        cls.addAttribute({
          name: member.name,
          type: new Type(member.idlType, include),
          readonly: member.readonly,
          defaultValue: new DefaultValue(member.default)
        });
      } else if (member.type === 'operation') {
        if (member.name) {
          cls.addMethod({
            name: member.name,
            type: new Type(member, include),
            args: new ArgumentList(member.arguments, include)
          });
        } else {
          // TODO: an operator without a name?
        }
      } else if (member.type === 'const') {
        assert.equal(member.nullable, false);
        cls.addConst({
          name: member.name,
          type: new Type(member, include),
          value: new Value(member.value)
        });
      } else if (member.type === 'iterable') {
        // TODO: what is an iterable member?
      } else {
        throw new TypeError(`unsupported member type ${member.type}`);
      }
    }

    super(content.name, cls, include);
  }
}

module.exports = Interface;
