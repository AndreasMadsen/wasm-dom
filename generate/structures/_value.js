'use strict';

class Value {
  constructor(idlValue) {
    if (!idlValue) {
      this.value = '';
    } else if (idlValue.type === 'null') {
      this.value = 'NULL'
    } else {
      this.value = idlValue.value.toString();
    }
  }

  toString() {
    return this.value;
  }
}

module.exports = Value;
