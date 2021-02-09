<?php
try
{
    $bdd = new PDO('mysql:host=localhost;dbname=project_db;charset=utf8', 'username', 'password'); //Specify here your database name, mysql username and password
}
catch(Exception $e)
{
    die('Erreur : '.$e->getMessage());
}

$req = $bdd->prepare('INSERT INTO Data(id, temperature, humidite, pression, latitude, longitude) 
    VALUES(:id, :temperature, :humidite, :pression, :latitude, :longitude)'); // The first line names must be the same as in your table. The second line names must be the same as is the last part of the code.

$id = NULL; // This is my PRIMARY KEY, I setuped with Auto Increment option, so I didn't need to put a value
$temperature = 0; // Defaults values
$humidite = 0;
$pression = 0;
$latitude = 0;
$longitude = 0;

if (isset($_POST['temperature'])) // This function catch the ESP32 value with HTTP POST method. The name must be the same as in the ESP32 code.
{
    $temperature = $_POST['temperature']; // Affect the ESP32 data to a local variable
}

if (isset($_POST['humidite']))
{
    $humidite = $_POST['humidite'];
}

if (isset($_POST['pression']))
{
    $pression = $_POST['pression'];
}

if (isset($_POST['latitude']))
{
    $latitude = $_POST['latitude'];
}

if (isset($_POST['longitude']))
{
    $longitude = $_POST['longitude'];
}

$req->execute(array(
    'id' => $id, // Mapping variables with mysql request
    'temperature' => $temperature,
    'humidite' => $humidite,
    'pression' => $pression,
    'latitude' => $latitude,
    'longitude' => $longitude
));

/*
You can replace lines 14 to 53 by :
$req->execute(array(
    'id' => NULL,
    'temperature' => $_POST['temperature'],
    'humidite' => $_POST['humidite'],
    'pression' => $_POST['pression'],
    'latitude' => $_POST['latitude'],
    'longitude' => $_POST['longitude']
));

This method work, but you can't specify default value if on of the variables isn't received.
*/

echo 'Fin de l\'ajout';