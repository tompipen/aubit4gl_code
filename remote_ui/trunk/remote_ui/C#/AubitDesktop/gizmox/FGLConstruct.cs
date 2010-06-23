using System;
using System.Collections.Generic;
using System.Text;

namespace AubitDesktop
{
    class FGLConstruct {
        
/**
 *
 *
 * @return
 */
        static public string
        getConstructString(string colName, string val, FGLUtils.FGLDataTypes dtype, int dtype_size)
        {
            //int a;
            string quote = "";
            bool allow_range_character = true;
            string colname;
            allow_range_character = true;
            int inc_quotes = 0;

            if (val == null || val.Trim() == "")
            {
                return ""; // Ignore it !
            }

            if (dtype == FGLUtils.FGLDataTypes.DTYPE_CHAR || dtype == FGLUtils.FGLDataTypes.DTYPE_NCHAR || dtype == FGLUtils.FGLDataTypes.DTYPE_VCHAR) inc_quotes = 1;
            if (dtype == FGLUtils.FGLDataTypes.DTYPE_DATE) inc_quotes = 2;
            if (dtype == FGLUtils.FGLDataTypes.DTYPE_DTIME) inc_quotes = 3;
            if (dtype == FGLUtils.FGLDataTypes.DTYPE_INTERVAL) inc_quotes = 4;

            if (inc_quotes > 0)
            {
                quote = "'";
            }

            colname = colName;
            if (colname.StartsWith("."))
            {
                colname = colname.Substring(1);
            }


            if (inc_quotes == 3 || inc_quotes == 4)
            {
                if (dtype == FGLUtils.FGLDataTypes.DTYPE_DTIME)
                {
                    string p;
                    int a;
                    // DATETIME RANGE KLUDGE
                    // one problem we have is if we have a datetime - and a range
                    //
                    // Lets figure out how long out datetime should be
                    // Quick and dirty way is to measure the length of
                    // a 'CURRENT' with the same dimensions...

                    p = String.Format(FGLUtils.formatForDatetime(dtype_size >> 4, dtype_size & 0xf));

                    if (p.Contains(":"))
                    {
                        // Darn - it contains a ':' - so we cant use this as a range character
                        allow_range_character = false;
                    }
                    else
                    {
                        allow_range_character = true;
                    }
                    a = p.Length;


                    if (allow_range_character == false)
                    {
                        // Special case - imagine HH:MM  to HH:MM
                        // We can use the specific size to check for HH:MM:HH:MM

                        if (val.Length > a)
                        {
                            // its a candidate..
                            if (val.Substring(a) == ":")
                            {
                                val = val.Substring(0, a - 1) + ".." + val.Substring(a + 1);
                            }
                        }
                    }
                }

            }




            string[] entries = val.Split('|');

            List<string> srch;

            srch = new List<string>();

            foreach (string v_e in entries)
            {
                string v;
                v = v_e.Trim();


                if (v == "=" || v == "=''")
                {
                    srch.Add("is null");
                    continue;
                }

                if (v == "!=" || v == "<>" || v == "<>''" || v == "!=''")
                {
                    srch.Add(colname + " is not null");
                    continue;
                }

                if (v.StartsWith(".."))
                {                           // We allow ..X and X.. to be <=X and >=X
                    v = "<=" + val.Substring(2);
                }

                if (v.StartsWith(":"))
                {
                    // We allow ..X and X.. to be <=X and >=X      
                    v = "<=" + val.Substring(2);
                }

                if (v.EndsWith(".."))
                {                           // We allow ..X and X.. to be <=X and >=X
                    v = ">=" + val.Substring(2);
                }

                if (v.EndsWith(":"))
                {
                    // We allow ..X and X.. to be <=X and >=X      
                    v = ">=" + val.Substring(2);
                }



                if (v.Contains(".."))
                {
                    string[] splt;
                    splt = new string[1];
                    splt[0] = "..";
                    string[] range = v.Split(splt, StringSplitOptions.None);
                    if (range.Length != 2)
                    {
                        return null;
                    }
                    else
                    {
                        if (!isConstructValueValid(dtype, dtype_size, range[0])) return null;
                        if (!isConstructValueValid(dtype, dtype_size, range[1])) return null;
                        srch.Add(colname + " between " + quoteEscape(range[0], quote) + " and " + quoteEscape(range[1], quote));
                    }
                }

                if (allow_range_character && v.Contains(":"))
                {
                    string[] splt;
                    splt = new string[1];
                    splt[0] = ":";
                    string[] range = v.Split(splt, StringSplitOptions.None);
                    if (range.Length != 2)
                    {
                        return null;
                    }
                    else
                    {
                        if (!isConstructValueValid(dtype, dtype_size, range[0])) return null;
                        if (!isConstructValueValid(dtype, dtype_size, range[1])) return null;
                        srch.Add(colname + " between " + quoteEscape(range[0], quote) + " and " + quoteEscape(range[1], quote));
                    }

                }


                if (v.StartsWith(">="))
                {
                    if (!isConstructValueValid(dtype, dtype_size, v.Substring(2)))
                    {
                        return null;
                    }
                    srch.Add(colname + ">=" + quoteEscape(v.Substring(2), quote));
                }

                if (v.StartsWith("<="))
                {
                    if (!isConstructValueValid(dtype, dtype_size, v.Substring(2)))
                    {
                        return null;
                    }
                    srch.Add(colname + "<=" + quoteEscape(v.Substring(2), quote));
                }

                if (v.StartsWith("<>") || v.StartsWith("!="))
                {
                    if (!isConstructValueValid(dtype, dtype_size, v.Substring(2)))
                    {
                        return null;
                    }

                    srch.Add(colname + "!=" + quoteEscape(v.Substring(2), quote));
                }

                if (v.StartsWith("=="))
                {
                    if (!isConstructValueValid(dtype, dtype_size, v.Substring(2)))
                    {
                        return null;
                    }

                    srch.Add(colname + "=" + quoteEscape(v.Substring(2), quote));
                }

                if (v.StartsWith("="))
                {
                    if (!isConstructValueValid(dtype, dtype_size, v.Substring(1)))
                    {
                        return null;
                    }
                    srch.Add(colname + "=" + quoteEscape(v.Substring(1), quote));
                }

                if (v.StartsWith(">"))
                {
                    if (!isConstructValueValid(dtype, dtype_size, v.Substring(1)))
                    {
                        return null;
                    }
                    srch.Add(colname + ">" + quoteEscape(v.Substring(1), quote));
                }
                if (v.StartsWith("<"))
                {
                    if (!isConstructValueValid(dtype, dtype_size, v.Substring(1)))
                    {
                        return null;
                    }
                    srch.Add(colname + "<" + quoteEscape(v.Substring(1), quote));
                }


                // Drop through to an "=" ...
                if (!isConstructValueValid(dtype, dtype_size, v))
                {
                    return null;
                }
                srch.Add(colname + "=" + quoteEscape(v, quote));

            }

            if (srch.Count == 0) return "";
            if (srch.Count == 1) return srch[0];
            string rval = "";

            foreach (string s in srch)
            {
                if (rval == "") rval = "(" + s + ")";
                else rval += " OR (" + s + ")";
            }
            return rval;

        }

        private static string quoteEscape(string p, string quote)
        {
            if (quote == null || quote == "")
            {
                return p;
            }

            if (quote == "'")
            {
                return quote + p.Replace("'", "\\'") + quote;
            }
            else
            {
                throw new ApplicationException("Invalid quote character");
            }
            
        }

        private static bool isConstructValueValid(FGLUtils.FGLDataTypes dtype, int dtype_size, string p)
        {
            return FGLUtils.IsValidForType(dtype, p, null, dtype_size);
        }

    }
}
