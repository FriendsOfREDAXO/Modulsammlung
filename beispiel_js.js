////////////////////////////////////////////////////////
// accordion
////////////////////////////////////////////////////////

    $('.accordioninhalt').hide();
    $('.accordionueberschrift').click(function() {
        $('.accordionueberschrift.aktiv').next('.accordioninhalt').slideUp(300);
        $('.accordionueberschrift').removeClass('aktiv');
        var divID = '#' + $(this).attr('rel');
        if ($(this).next().is(':hidden') == true) {
            $(this).addClass('aktiv');
            var aktuell = $(this).next();

            if ($('.accordionueberschrift').length > 1) {
                $('.accordionueberschrift').not('.aktiv').next('.accordioninhalt').slideUp(300, function() {
                    aktuell.slideDown(300, function() {
                        //  console.log($('.accordionueberschrift').not( ".aktiv" ).next('.accordioninhalt'));
                        //  $('html, body').animate({ scrollTop: $(divID).offset().top-15}, 300);
                    });
                });
            } else {
                $('.accordioninhalt').slideDown(300);
            }
        }
    });
    $('.accordionueberschrift').mouseover(function() {
        $(this).addClass('hover');
    }).mouseout(function() {
        $(this).removeClass('hover');
    });
    
////////////////////////////////////////////////////////
