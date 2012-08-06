Arduino led-communication
=========================
Implémentation d'un protocole de communication via une led et une photorésistance.

* L'émetteur est un raspberry pi. Les pins sont commandé par un programe en C qui utilise la lib WiringPi (https://projects.drogon.net/raspberry-pi/wiringpi/)
  * Pour compiler (après avoir installé la lib) : g++ -o emetteur emetteur.cpp -L/usr/local/lib -lwiringPi
* Le récepteur est un arduino uno

--

Structure d'un paquet :

<table>
  <tr>
    <th>Init</th>
    <th>Taille</th>
    <th>Message</th>
    <th>Checksum</th>
  </tr>
  <tr>
    <td>1 bit</td>
    <td>5 bits</td>
    <td>max 217 bits</td>
    <td>(non implémenté)</td>
  </tr>
</table>
--

Une lettre : 7 bits
Taille max message : 31 lettres
Debit : 50 bits/sec
Temps max de transmision d'un paquet : 5.1 sec