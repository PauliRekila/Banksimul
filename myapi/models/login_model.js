const db = require('../database');

const login={
  checkPassword: function(korttinumero, callback) {
      return db.query('SELECT pinkoodi FROM kortti WHERE korttinumero = ?',[korttinumero], callback); 
    }
};
          
module.exports = login;