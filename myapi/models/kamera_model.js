const db = require('../database');

const kamera={
    tallenna_kuva: function(procedure_params, callback) {
        return db.query(
          'CALL tallenna_kuva(?)',
          [procedure_params.polku],
          callback
        );
      }
    };

module.exports = kamera;