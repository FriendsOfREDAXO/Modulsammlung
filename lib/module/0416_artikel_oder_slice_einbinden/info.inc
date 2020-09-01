<h4><b>0416 - Artikel oder Slice einbinden</b></h4>
<p>Manchmal benötigt man eine Information, die bereits in einem Artikel eingepflegt ist. Natürlich kann man diese kopieren oder doppelt pflegen, was jedoch dazu führen kann, dass diese Informationen nicht immer auf dem aktuellen Stand sind. Eine Lösung hierfür ist die Einbindung zentral gepflegter Artikel oder Tabellendaten. Eine andere ist die Einbindung eines Slices.
</p>
<p>
Mit diesem Modul bindet man einen ausgewählen Slice eines anderen Artikels ein oder bei Bedarf einen ganzen Artikel. Das Modul basiert auf das Slice-HiJacker-Modul von Mirco Brandes/Gerald Rusche für REDAXO 4.x. Es wird zusätzlich eine Presave-Aktion benötigt.
</p>

<h2> Folgende Aktion muss angelegt werden </h2>
<p>
Presave-Action	
</p> 

<pre>

if ($this->getValue(2) == '0') {
   // Der Block wird nicht gespeichert
   $this->save = false;
   // Meldung ausgeben
   $this->messages[] = 'Bitte noch einen Slice/Block auswaehlen';
}	

</pre>
