const express = require("express");
const fibonacci = require('bindings')('fibonacci');
const app = express();

app.set('view engine', 'ejs');

app.get('/', function (request, response) {
    response.render("index", {
        next: fibonacci.get()
    });
});

app.listen(3000);
