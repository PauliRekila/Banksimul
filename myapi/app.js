var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');


var asiakasRouter = require('./routes/asiakas');
var korttiRouter = require('./routes/kortti');
var tiliRouter = require('./routes/tili');
var tapahtumatRouter = require('./routes/tapahtumat');
var loginRouter = require('./routes/login');
var kameraRouter = require('./routes/kamera');


var app = express();

const basicAuth = require('express-basic-auth');
app.use(basicAuth({users: { 'banksimul35': '1234' }}))

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/asiakas', asiakasRouter);
app.use('/kortti', korttiRouter);
app.use('/tili', tiliRouter);
app.use('/tapahtumat', tapahtumatRouter);
app.use('/login', loginRouter);
app.use('/kamera', kameraRouter);

module.exports = app;
