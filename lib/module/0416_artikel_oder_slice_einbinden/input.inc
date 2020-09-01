<?php
//------------------------------------------------------------------------------------------
// Ursprung: Slice-HiJacker für REDAXO 4.3.2
// von: Mirco Brandes/Gerald Rusche GERUWEB
//-------------------------------------------------------------------------------------------
?>
<div class="alert alert-dismissible alert-info"> Mit diesem Block können Sie Inhalte anderer Artikel veröffentlichen bzw. einbinden. Bitte beachten Sie: Wenn das Original gelöscht wird wirkt sich dies auch auf den Inhalt des Artikels, in dem der Inhalt eingebunden ist, aus. Es wird keine Kopie erstellt. Die Daten sind miteinander verknüpft. Wird im Original was verändert sieht man die Änderung auch an dieser Stelle. </div>
<input type="hidden" name="REX_INPUT_VALUE[2]" value="0" />
<div class="form-horizontal">
    <div class="form-group">
        <label class="col-sm-2 control-label">Artikel ausw&auml;hlen</label>
        <div class="col-sm-10">
            REX_LINK[id=1 widget=1]
        </div>
     </div>
</div>
<?php
if( "REX_LINK[id=1 output=id]" == "" )
{
  echo "Kein Artikel ausgewaehlt";
}
else if ( "REX_LINK[id=1 output=id]" == $this->getValue("article_id") )
{
  echo "Der ausgewaehlte Artikel muss ein anderer sein, als der aktuelle !!!";
}
else
{
  // Radio-Button - kompletten Artikel einbinden ???
  echo '<div class="form-horizontal">';
    print "<input ";
  if("REX_VALUE[2]" == "kompletter_artikel") print "checked";
  print " type='radio'  name='REX_INPUT_VALUE[2]' id='kompletter_artikel' value='kompletter_artikel' /> Artikel komplett einbinden ?";
echo '</div>';

  // Alle Slice/Bloecke anzeigen
  print "<h2>Slice/Block auswählen:</h2>";

  $article_id = "REX_LINK[id=1 output=id]";
  $clang = rex_clang::getCurrentId();

  // Den ersten Slice/Block des Artikelt holen
  $slice = rex_article_slice::getFirstSliceForArticle($article_id, $clang);

  do
  {
    // Slice-ID zwischenspeichern
    $slice_id = $slice->getId();

    // Radio-Button zur Auswahl
print "<div style='background-color: #fff ;border: 1px solid #333; display:block; width: 100%; padding: 5px; margin: 10px;'>";
        echo '<div class="form-horizontal">';
print "<input ";
    if("REX_VALUE[2]" == $slice_id) print "checked";
    print " type='radio'  name='REX_INPUT_VALUE[2]' id='".$slice_id."' value='".$slice_id."' /> (Slice-ID: ". $slice_id .")</div><hr/>";
    // Den Slice/Block ausgeben
    print $slice->getSlice() ."<div style='display:block;clear:both;'></div></div>";


  } while (($slice = $slice->getNextSlice()) !== null);
}