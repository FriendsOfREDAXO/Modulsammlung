<?php
//------------------------------------------------------------------------------------------
// Ursprung: Slice-HiJacker für REDAXO 4.3.2
// von: Mirco Brandes/Gerald Rusche GERUWEB
// Version 3 - 13.02.2025
//-------------------------------------------------------------------------------------------
?>
<div class="alert alert-dismissible alert-info"> Mit diesem Block können Sie Inhalte anderer Artikel veröffentlichen bzw. einbinden. Bitte beachten Sie: Wenn das Original gelöscht wird wirkt sich dies auch auf den Inhalt des Artikels, in dem der Inhalt eingebunden ist, aus. Es wird keine Kopie erstellt. Die Daten sind miteinander verknüpft. Wird im Original was verändert sieht man die Änderung auch an dieser Stelle. </div>

<?php
// Prüfen ob der ausgewählte Artikel noch existiert
if ("REX_LINK[1]" != "" && !rex_article::get("REX_LINK[1]")) {
    echo '<div class="alert alert-danger">
        <strong>Achtung:</strong> Der zuvor ausgewählte Artikel existiert nicht mehr! 
        <br>Bitte wählen Sie einen neuen Artikel aus oder löschen Sie diesen Block.
        <br><br>
        <button class="btn btn-danger" onclick="deleteBlock()">Block löschen</button>
    </div>';
}

// Prüfen ob der ausgewählte Slice noch existiert
if ("REX_VALUE[2]" != "" && "REX_VALUE[2]" != "kompletter_artikel" && !rex_article_slice::getArticleSliceById("REX_VALUE[2]")) {
    echo '<div class="alert alert-danger">
        <strong>Achtung:</strong> Der zuvor ausgewählte Block/Slice existiert nicht mehr! 
        <br>Bitte wählen Sie unten einen neuen Block aus oder löschen Sie diesen Block.
        <br><br>
        <button class="btn btn-danger" onclick="deleteBlock()">Block löschen</button>
    </div>';
}
?>

<input type="hidden" name="REX_INPUT_VALUE[2]" value="0" />
<div class="form-horizontal">
    <div class="form-group">
        <label class="col-sm-2 control-label">Artikel ausw&auml;hlen</label>
        <div class="col-sm-10">
            REX_LINK[id=1 widget=1]
        </div>
     </div>
</div>

<script>
function deleteBlock() {
    if (confirm('Möchten Sie diesen Block wirklich löschen?')) {
        // Slice-ID aus der URL holen
        const urlParams = new URLSearchParams(window.location.search);
        const sliceId = urlParams.get('slice_id');
        
        if (sliceId) {
            window.location.href = 'index.php?page=content&article_id=<?php echo rex_article::getCurrentId(); ?>&mode=edit&slice_id=' + sliceId + '&function=delete&_csrf_token=<?php echo rex_csrf_token::factory("slice")->getValue(); ?>';
        }
    }
}
</script>

<?php
if( "REX_LINK[1]" == "" )
{
    echo '<div class="alert alert-warning">Kein Artikel ausgewählt</div>';
}
else if ( "REX_LINK[id=1 output=id]" == rex_article::getCurrentId() )
{
    echo '<div class="alert alert-danger">Der ausgewählte Artikel muss ein anderer sein als der aktuelle!</div>';
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
    
    if ($slice) {
        do {
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
    } else {
        echo '<div class="alert alert-warning">Der ausgewählte Artikel enthält keine Blöcke.</div>';
    }
}
?>
