using System;
using System.Collections.Generic;
using System.Text;

namespace AubitDesktop
{
    class FormattedCellSettings
    {
        internal string format;
        internal bool Required;
        internal List<string> includeValues;
        internal FGLUtils.FGLDataTypes datatype;
        internal int datatype_length;
        internal string defaultValue;
        internal bool upshift;
        internal bool downshift;
        internal string comments;
        internal bool isPassword;
        internal bool readOnly;


        internal FormattedCellSettings()
        {
            format = null;
            Required = false;
            datatype = FGLUtils.FGLDataTypes.DTYPE_CHAR;
            includeValues = null;
            defaultValue = "";
            upshift = false;
            downshift = false;
            comments = "";
            isPassword = false;
            readOnly = false;

        }

    }

}
