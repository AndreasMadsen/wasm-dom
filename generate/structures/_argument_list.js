'use strict';

const Argument = require('./_argument.js');

class ArgumentList {
  constructor(args, include) {
    this.args = (args || []).map(
      (arg) => new Argument(arg, include)
    )
  }

  *[Symbol.iterator]() {
    // TODO: support optional arguments

    // construct a list of iterables, these may be reset later
    const iterators = this.args.map((arg) => arg[Symbol.iterator]());

    // We know each argument has at least one value
    const args = iterators.map((iterator) => iterator.next().value);
    yield args;

    // early stop if empty list
    if (this.args.length === 0) return;

    combinations: while (true) {
      argsLoop: for (let i = iterators.length - 1; i >= 0; i--) {
        const next = iterators[i].next();
        if (next.done) {
          // reset iterator
          iterators[i] = this.args[i][Symbol.iterator]();
          // get the first item
          args[i] = iterators[i].next().value;
          if (i === 0) {
            // all combinations are exuasted
            break combinations;
          } else {
            // move the next iterator
            continue argsLoop;
          }
        } else {
          args[i] = next.value;
          // move the first iterator
          yield args.slice(0);
          break argsLoop;
        }
      }
    }
  }

  toString() {
    return this.args.join(', ');
  }
}

module.exports = ArgumentList;
