'use strict';

const fs = require('fs');
const path = require('path');
const async = require('async');
const request = require('request');
const webIDL2 = require('webidl2');
const endpoint = require('endpoint');
const WebIDLExtract = require('webidl-extract');

const sources = JSON.parse(fs.readFileSync(
  path.resolve(__dirname, 'webidl-sources.json'), 'utf8'
));

async.eachSeries(sources, function ({name, href}, done) {
  request(href)
    .pipe(new WebIDLExtract())
    .pipe(endpoint(function (err, webidl) {
      if (err) return done(err);

      const webIDLJSON = JSON.stringify(
        webIDL2.parse(webidl.toString()),
        null, 2
      );

      fs.writeFile(
        path.resolve(__dirname, '..', 'webidl', `${name}.json`),
        webIDLJSON,
        done
      );
    }));
}, function (err) {
  if (err) throw err;
});
