
<script type="text/javascript">
    jQuery(function($){

//--- Functions ---///

        function get_dyn_table_data() {
            var table_data = '';
            i=0;
            $('div#dyntable table tr[class!="control"]').each(function() {
                if(i>0) {
                    table_data = table_data+'[ROW|ROW]';
                }
                i++;

                j=0;
                $(this).children('.dyn_content').each(function() {
                    if(j>0) {
                        table_data = table_data+'[COL|COL]';
                    }
                    j++;
                    var fieldvalue = $(this).children().first().val();
                    var fieldvalue_clean = fieldvalue.replace('[COL|COL]', '[col|col]').replace('[ROW|ROW]', '[row|row]');
                    table_data = table_data+fieldvalue_clean;
                });
            });
            $('#debugout').html(table_data);
            $('#dyntable_string').val(table_data);

        }

        function generate_dyn_table() {
            var table_data = $('#dyntable_string').val();
            var table_rows = table_data.split('[ROW|ROW]');
            var table_cols = table_rows[0].split('[COL|COL]');

            for(var i=1; i<table_cols.length;i++) {
                add_dyn_table_col();
            }

            for(var i=1; (i+1)<table_rows.length-1;i++) {
                add_dyn_table_row();
            }

            update_dyn_table_counter();

            for(var i=0;i<table_rows.length;i++) {
                table_cols = table_rows[i].split('[COL|COL]');

                for(var j=0; j<table_cols.length; j++) {
                    if(i == 0) {
                        // Kopfzeile thead
                        $('th[data-col="'+(j+2)+'"][data-row="'+(i+2)+'"] input').val(table_cols[j]);
                    } else if(i == table_rows.length-1) {
                        // Fußzeile tfoot
                        $('td[data-col="'+(j+2)+'"][data-row="'+(i+2)+'"] input').val(table_cols[j]);
                    } else {
                        // Inhalt tbody
                        $('td[data-col="'+(j+2)+'"][data-row="'+(i+2)+'"] textarea').html(table_cols[j]);
                    }
                }
            }

            get_dyn_table_data();
        }

        function update_dyn_table_counter() {
            i=1;

            $('div#dyntable table tr').each(function() {
                j=1;

                $(this).children().each(function() {
                    $(this).attr('data-row', i);
                    $(this).attr('data-col', j);
                    j++;
                });

                i++;
            });
        }

        function add_dyn_table_col() {
            $('div#dyntable_show table tr[class!="control"][class!="dyn_head"][class!="dyn_foot"]').append('<td class="dyn_content"><textarea style="width:95%"></textarea></td>');
            $('div#dyntable_show table tr[class="dyn_head"][class!="control"]').append('<th class="dyn_content"><input style="width:95%"/></th>');
            $('div#dyntable_show table tr[class="dyn_foot"][class!="control"]').append('<td class="dyn_content"><input style="width:95%"/></td>');
            $('div#dyntable_show table tr[class="control"]').append('<th class="leftrighticons"><a href="#" class="dyntable_del_col" ></a><a href="#" class="left"></a><a href="#" class="right"></a></th>');
        }

        function add_dyn_table_row() {
            var count = $('div#dyntable_show table tr.control th').length;
            var rowout = '';
            for (var i=0; i<(count-1); i++){
                rowout = rowout+'<td class="dyn_content"><textarea style="width:95%"></textarea></td>';
            }

            //$('div#dyntable_show table').append('<tr><td><a href="#" class="dyntable_del_row"></a><a href="#" class="up" ></a><a href="#" class="down"></a></td>'+rowout+'</tr>');
            $('<tr><td><a href="#" class="dyntable_del_row"></a><a href="#" class="up" ></a><a href="#" class="down"></a></td>'+rowout+'</tr>').insertBefore('div#dyntable_show table tr.dyn_foot');
        }

        function move_table_col(from,to) {
            var rows = $('tr', '#dyntable_show table');
            var cols;
            rows.each(function() {
                cols = $(this).children('th, td');
                cols.eq(from).detach().insertBefore(cols.eq(to));
            });
            get_dyn_table_data();
            update_dyn_table_counter();
        }

//--- Events ---//

        $('#dyntable_add_col').click(function(e) {
            e.preventDefault();
            add_dyn_table_col();
            update_dyn_table_counter();
            get_dyn_table_data();
        });
        $('#dyntable_add_row').click(function(e) {
            e.preventDefault();
            add_dyn_table_row();
            update_dyn_table_counter();
            get_dyn_table_data();
        });


        $('#dyntable_show').on('click', '.up,.down', function(e){
            e.preventDefault();
            var row = $(this).closest('tr');

            if ($(this).is(".up")) {
                var index = $( "tr" ).index( $(this).parent().parent() );
                if(index>2)
                    row.insertBefore(row.prev());
            } else {
                row.insertAfter(row.next());
            }
            get_dyn_table_data();
        });


        $('#dyntable_show').on('click', '.left,.right', function(e) {
            e.preventDefault();
            var index = $( "th" ).index( $(this).parent() );

            if($(this).is('.left')) {
                if(index > 1) {
                    move_table_col(index, index - 1);
                }
            }
            else {
                move_table_col(index+1, index);
            }
        });

        $('#dyntable_show').on('click', '.dyntable_del_col' ,function(e) {
            e.preventDefault();
            var col = $(this).parent().attr('data-col');
            $('th[data-col="'+col+'"],td[data-col="'+col+'"]').remove();
            get_dyn_table_data();
        });

        $('#dyntable_show').on('click', '.dyntable_del_row', function(e) {
            e.preventDefault();
            var row = $(this).parent().attr('data-row');
            $(this).parent().parent().remove();
            get_dyn_table_data();
        });

        $('div#dyntable').on('change', 'input,textarea', function() {
            get_dyn_table_data();
        });

//--- Initial execution ---//

        generate_dyn_table();

    });
</script>


<div id="dyntable" class="modul-content">
    <div class="form-horizontal">
        <h3 class="ueberschrift">Tabelle</h3>
        <div class="form-group">
            <div class="col-xs-12">
                <input id="dyntable_string" type="hidden" class="text'.$classes.$wc.'" name="REX_INPUT_VALUE[1]" id="test" value="REX_VALUE[1]">
                <div id="dyntable_show">
                    <label for="tableclass">CSS-Klasse</label> &nbsp; <input type="text" name="REX_INPUT_VALUE[2]" id="tableclass" value="REX_VALUE[2]" style="width: 100%;"><br><br>
                    <label for="tablecaption">Überschrift (Caption)</label> &nbsp; <input type="text" name="REX_INPUT_VALUE[3]" id="tablecaption" value="REX_VALUE[3]" style="width: 100%;"><br><br><br>
                    <table>
                        <tr class="control">
                            <th >
                                <a id="dyntable_add_row" href="#"></a>
                                <a id="dyntable_add_col" href="#"></a>
                            </th>
                            <th class="leftrighticons">
                                <a href="#" class="dyntable_del_col"></a>
                                <a href="#" class="left"></a>
                                <a href="#" class="right"></a>
                            </th>
                        </tr>
                        <tr class="dyn_head">
                            <th>Kopfzeile</th>
                            <th class="dyn_content">
                                <input type="text" style="width:95%"/>
                            </th>
                        </tr>
                        <tr>
                            <td>
                                <a href="#" class="dyntable_del_row"></a>
                                <a href="#" class="up"></a>
                                <a href="#" class="down"></a>
                            </td>
                            <td class="dyn_content">
                                <textarea style="width:95%"></textarea>
                            </td>
                        </tr>
                        <tr class="dyn_foot">
                            <th>Fußzeile</th>
                            <td class="dyn_content">
                                <input type="text" style="width:95%"/>
                            </td>
                        </tr>
                    </table>
                    <br><br><label for="tablelegend">Legende</label> &nbsp; <input type="text" name="REX_INPUT_VALUE[4]" id="tablelegend" value="REX_VALUE[4]" style="width: 100%;">
                </div>
            </div>
        </div>
    </div>
</div>

<style>
    #dyntable {
        background: #f5f5f5;
        padding: 10px 30px 30px 15px;
        border: 1px solid #9da6b2;
    }

    #dyntable table {
        background: none;
    }

    #dyntable a#dyntable_add_row:before,
    #dyntable a#dyntable_add_col:before,
    #dyntable a.dyntable_del_row:before,
    #dyntable a.dyntable_del_col:before,
    #dyntable a.left:before,
    #dyntable a.right:before,
    #dyntable a.up:before,
    #dyntable a.down:before {
        display: inline-block;
        font-family: 'FontAwesome';
        font-size: 1em;
        width: 18px;
        line-height: 1.6;
        text-align: center;
        font-weight: normal;
        float: left;
        background: none;
    }

    #dyntable a#dyntable_add_row:hover {
        text-decoration: none;
    }

    #dyntable a#dyntable_add_row:before{
        content: "\f078";
        width: 22px;
    }

    #dyntable a#dyntable_add_col:before {
        content: "\f054";
        width: 22px;
    }

    #dyntable a.dyntable_del_row:before,
    #dyntable a.dyntable_del_col:before {
        content: "\f014";
    }

    #dyntable a.left:before {
        content: "\f104";
    }

    #dyntable a.right:before {
        content: "\f105";
    }

    #dyntable a.up:before {
        content: "\f106";
    }

    #dyntable a.down:before {
        content: "\f107";
    }

    #dyntable .control th {
        min-width: 60px;
        padding-bottom: 15px;
    }

    #dyntable .dyn_head th,
    #dyntable .dyn_head td {
        padding: 10px 0 15px 0 !important;
    }

    #dyntable .dyn_head th:first-child {
        padding-right: 15px !important;
    }

    #dyntable .dyn_foot th,
    #dyntable .dyn_foot td {
        padding: 10px 0 0 0 !important;
    }

    #dyntable input,
    #dyntable textarea{
        border: 1px solid #E0E3E9;
    }

    #dyntable_show {
        overflow: auto;
    }

    #dyntable h3.ueberschrift {
        font-size: 14px !important;
        padding: 10px;
        background: #DFE3E9;
        width: 100%;
        margin-bottom: 20px;
    }
</style>
