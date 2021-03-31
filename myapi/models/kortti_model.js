const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where idkortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
    bcrypt.hash(kortti.pinkoodi, saltRounds, function(err, hash){
    return db.query(
      'insert into kortti (korttinumero,pinkoodi,lukittu,idtili) values(?,?,?,?)',
      [kortti.korttinumero, hash, kortti.lukittu, kortti.idtili],
      callback) 
      })
   },
  delete: function(id, callback) {
    return db.query('delete from kortti where idkortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    bcrypt.hash(kortti.pinkoodi, saltRounds, function(err, hash){
    return db.query(
      'update kortti set korttinumero=?,pinkoodi=?, lukittu=?,idtili=? where idkortti=?',
      [kortti.korttinumero, hash, kortti.lukittu, kortti.idtili, id],
      callback)
    });
  },
  uusi_tapahtuma: function(procedure_params, callback) {
    return db.query(
      'CALL uusi_tapahtuma(?,?)',
      [procedure_params.id, procedure_params.maara],
      callback
    );
  }  
};
module.exports = kortti;