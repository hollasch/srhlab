// This script computes the appropriate format for printing min/max values

var getFormat = function(lo,hi) {
    var deltaExponent = Math.floor(Math.log10(hi-lo))
    var numFracDigits = Math.max(0, -deltaExponent + 3)
    var format = ',.' + numFracDigits + 'f'

    console.log (lo +' - ' +hi
        +' = deltaExponent ' +deltaExponent
        +', numFracDigits ' +numFracDigits
        +', format "' +format +'"')
}

getFormat (0,1)
getFormat (0,10)
getFormat (0.112345,0.112781)
getFormat (121, 6411)
getFormat (5011, 6411)
getFormat (-112, -55)
getFormat (-0.0012, -0.0007)
getFormat (-0.0012, -0.00007)
getFormat (-112, 47)
getFormat (3, 12345699)
