const db = require('../database');

const tapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tapahtumat where idtapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tapahtumat', callback);
  },
  add: function(tapahtumat, callback) {
    return db.query(
      'insert into tapahtumat (maara,paivays,tyyppi,idtili) values(?,?,?,?)',
      [tapahtumat.maara, tapahtumat.paivays, tapahtumat.tyyppi, tapahtumat.idtili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tapahtumat where idtapahtumat=?', [id], callback);
  },
  update: function(id, tapahtumat, callback) {
    return db.query(
      'update tapahtumat set maara=?,paivays=?, tyyppi=?,idtili=? where idtapahtumat=?',
      [tapahtumat.maara, tapahtumat.paivays, tapahtumat.tyyppi, tapahtumat.idtili, id],
      callback
    );
  }
};
module.exports = tapahtumat;