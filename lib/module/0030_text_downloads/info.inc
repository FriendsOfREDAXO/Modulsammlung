<h4><b>Text / Download</b></h4>

Diese Modul ermöglicht es einen Text &amp; Downloads zu verwalten.
<br/><br/>
<p><b>Voraussetzungen</b></p>
<ul>
  <li>MarkItUp Addon<br/>Beim ersten Aufruf des Moduls wird das jeweilige Profil angelegt. Danach sollte MarkItUp funktionieren.</li>
</ul>

<br/>
<p>…weitere Infos bzgl. schöner URLs finden sich in der Doku</p>

<hr/>
<p>Wem der Download Pfad nicht gefällt, der wandelt die .htaccess noch ab:</p>

<pre>RewriteRule ^media/([^/]*)/([^/]*) %{ENV:BASE}/index.php?rex_media_type=$1&rex_media_file=$2&%{QUERY_STRING} [B]</pre>
<p>Der Download erfolgt dann über /media/download/dateiname.pdf</p>

<p>Oder:</p>

<pre>RewriteRule ^download/([^/]*) %{ENV:BASE}/index.php?rex_media_type=download&rex_media_file=$1&%{QUERY_STRING} [B]</pre>
<p>Der Download erfolgt dann direkt über /download/dateiname.pdf</p>