'use strict';

const Argument = require('./_argument.js');

class ArgumentList {
  constructor(args, include) {
    this.args = (args || []).map(
      (arg) => new Argument(arg, include)
    )
  }

  *[Symbol.iterator]() {
    yield this.args;
  }

  toString() {
    return this.args.join(', ');
  }
}

module.exports = ArgumentList;
