'use strict';

class DefaultValue {
  constructor(idlDefault) {
    this.exists = false;
    this.value = '';

    if (idlDefault) {
      this.exists = true;

      if (idlDefault.type === 'null') {
        this.value = 'NULL'
      } else {
        this.value = idlDefault.value.toString();
      }
    }
  }

  toString() {
    return this.value;
  }
}

module.exports = DefaultValue;
