'use strict';

const Value = require('./_value.js');

class DefaultValue extends Value {
  constructor(idlDefault) {
    super(idlDefault);
    this.exists = !!idlDefault;
  }
}

module.exports = DefaultValue;
