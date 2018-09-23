** END HEADER -- Diese Zeile nicht löschen*
// Erstellt am 14.01.1997
//
parameter bModal
local f
f = new MainFormular()
if (bModal)
    f.mdi = .F.        && ensure mdi
    f.ReadModal()
else
    f.Open()
endif

CLASS MainFormular OF FORM

    this.width = 300

ENDCLASS
