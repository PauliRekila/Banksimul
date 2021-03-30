const db = require('../database');

const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where idkortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
    return db.query(
      'insert into kortti (korttinumero,pinkoodi,lukittu,idtili) values(?,?,?,?)',
      [kortti.korttinumero, kortti.pinkoodi, kortti.lukittu, kortti.idtili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where idkortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    return db.query(
      'update kortti set korttinumero=?,pinkoodi=?, lukittu=?,idtili=? where idkortti=?',
      [kortti.korttinumero, kortti.pinkoodi, kortti.lukittu, kortti.idtili, id],
      callback
    );
  }
};
module.exports = kortti;