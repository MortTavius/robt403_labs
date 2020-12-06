
"use strict";

let state = require('./state.js');
let rigid = require('./rigid.js');
let coord = require('./coord.js');
let fsrInput = require('./fsrInput.js');
let accelerometr = require('./accelerometr.js');
let newtactile = require('./newtactile.js');
let contact = require('./contact.js');
let tactile = require('./tactile.js');

module.exports = {
  state: state,
  rigid: rigid,
  coord: coord,
  fsrInput: fsrInput,
  accelerometr: accelerometr,
  newtactile: newtactile,
  contact: contact,
  tactile: tactile,
};
