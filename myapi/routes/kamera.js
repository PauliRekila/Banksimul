const express = require('express');
const router = express.Router();
const kamera = require('../models/kamera_model');

router.post('/', 
function(request, response) {
  kamera.tallenna_kuva(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

module.exports = router;