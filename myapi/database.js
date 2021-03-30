const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: '1234',
  database: 'banksimul35'
});
module.exports = connection;