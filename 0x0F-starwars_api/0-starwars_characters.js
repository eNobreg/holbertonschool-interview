#!/usr/bin/node
const request = require('request');

const options = {
  url: 'https://swapi-api.hbtn.io/api/films/' + process.argv[2]
};

request(options, async function (err, res, body) {
  if (err) { console.log(err); }
  const json = JSON.parse(body);

  for (const entry of json.characters) {
    await new Promise(function (resolve, reject) {
      request(entry, function (err, res, body) {
        if (err) {
          reject(err);
        } else {
          console.log(JSON.parse(body).name);
          resolve();
        }
      });
    });
  }
});
