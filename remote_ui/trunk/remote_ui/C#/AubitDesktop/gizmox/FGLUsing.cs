/*
 *  Copyright (c) 2008 The Aubit Development Team. 
 *  All rights reserved. See CREDITS file.
 *  
 *  
 *  This file is part of Aubit 4gl.
 *
 *  Aubit 4gl is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as 
 *  published by the Free Software Foundation.
 *
 *  Aubit 4gl is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Aubit 4gl.  If not, see <http://www.gnu.org/licenses/>.
 */

using System;
using System.Collections.Generic;
using System.Text;

namespace AubitDesktop
{
    class FGLUsing
    {

        public static string A4GL_func_using(string fmt, string value, FGLUtils.FGLDataTypes dt)
        {


            switch (dt)
            {
                case FGLUtils.FGLDataTypes.DTYPE_DECIMAL:
                case FGLUtils.FGLDataTypes.DTYPE_MONEY:
                    bool isneg = false;
                    char[] p;
                    p = value.ToCharArray();
                    for (int a = 0; a < p.Length; a++)
                    {
                        if (p[a] >= '0' && p[a] <= '9') continue;
                        if (p[a] == '.') { p[a] = '.'; continue; }
                        if (p[a] == '-') { p[a] = ' '; isneg = true; continue; }
                        p[a] = ' ';
                    }

                    return a4gl_using_from_string(fmt, value, isneg);



                case FGLUtils.FGLDataTypes.DTYPE_BYTE:
                case FGLUtils.FGLDataTypes.DTYPE_SMINT:
                case FGLUtils.FGLDataTypes.DTYPE_INT:
                case FGLUtils.FGLDataTypes.DTYPE_SERIAL:
                case FGLUtils.FGLDataTypes.DTYPE_SMFLOAT:
                case FGLUtils.FGLDataTypes.DTYPE_FLOAT:
                    return a4gl_using(fmt, value);

                case FGLUtils.FGLDataTypes.DTYPE_DATE:

                    return a4gl_using_date(fmt, value);

                case FGLUtils.FGLDataTypes.DTYPE_CHAR:
                case FGLUtils.FGLDataTypes.DTYPE_NULL:
                case FGLUtils.FGLDataTypes.DTYPE_DTIME:
                case FGLUtils.FGLDataTypes.DTYPE_TEXT:
                case FGLUtils.FGLDataTypes.DTYPE_VCHAR:
                case FGLUtils.FGLDataTypes.DTYPE_INTERVAL:
                case FGLUtils.FGLDataTypes.DTYPE_NCHAR:
                default:
                    if (fmt.Contains("dd") || fmt.Contains("mm") || fmt.Contains("yy") ||
                        fmt.Contains("DD") || fmt.Contains("MM") || fmt.Contains("YY"))
                    {
                        return a4gl_using_date(fmt, value);
                    }
                    else
                    {
                        return a4gl_using(fmt, value);
                    }
            }
        }

        private static string a4gl_using_from_string(string fmt, string value, bool isneg)
        {

            
            string overflow;
            string fm1 = "";
            string fm2 = "";
            
            string str_as_string;
            bool has_money = false;
            int p = 0;
            int num_places = 64;
            char[] canfloat_head = { '*', '-', '+', '(', '$' };
            char[] rep_digit = { '*', '&', '#', '<', '-', '+', '(', ')', '$' };
            string buff;
            int a = 0, variable_called_b = 0;
            bool isprnt = false;
            string buff_decimal;
            string buff_integer;
            int s;
            //string ptr_decimal;
            char[] str;

            decimal M_main;
            

            int lb = 0;
            int cb = 0;



            s = fmt.Length; /// @FIXME - this used to be passed in as a parameter...




            overflow = "";
            overflow = overflow.PadLeft(fmt.Length, '*');

            for (a = 0; a < fmt.Length; a++)
            {
                if (fmt.Substring(a, 1) == "(") lb++;
                if (fmt.Substring(a, 1) == ")") cb++;
            }




            if (lb > 1 && cb > 1)
            {
                throw new ApplicationException("Cant have more than one '(' and more than one ')' in a format string");

            }


            if (lb > 0 && cb > 0)
            { // we've got some brackets..


                char[] buff2;

                
                int eob;
                buff = fmt.Substring(fmt.IndexOf("(") + 1);
                eob = buff.IndexOf(")");
                if (eob == -1)
                { // its all gone pete tong..
                    return "";
                }
                buff = buff.Substring(0, eob - 1);
                buff2 = buff.ToCharArray();

                for (a = 0; a < buff2.Length; a++)
                {
                    if (lb == 1 && cb == 1)
                    {
                        if (buff2[a] == '(') buff2[a] = '#';
                        if (buff2[a] == ')') buff2[a] = '#';
                    }

                    if (lb > 1 && cb == 1)
                    {
                        if (buff2[a] == '(') buff2[a] = '#';
                    }
                    if (lb == 1 && cb > 1)
                    {
                        if (buff2[a] == ')') buff2[a] = '#';
                    }

                }

                string res = a4gl_using_from_string(new string(buff2), value, false);
                string fmtorig = fmt;
                fmt = fmt.Substring(0, fmt.IndexOf("(")+1);
                    fmt+= res;
                fmt+=fmtorig.Substring(eob + 1);

                if (!isneg)
                {
                    if (fmt.IndexOf("(") >= 0 && fmt.IndexOf(")") >= 0)
                    {
                        
                        fmt=fmt.Replace("(", " ");
                        fmt=fmt.Replace(")", " ");
                    }
                    else
                    {
                        if (lb > 1)
                        {
                            char[] cfmt;
                            cfmt = fmt.ToCharArray();
                            for (a = 0; a < cfmt.Length; a++)
                            {
                                if (cfmt[a] == '(' && cfmt[a + 1] == ' ')
                                {
                                    cfmt[a] = ' ';
                                    cfmt[a + 1] = '(';
                                }
                            }
                            fmt = new string(cfmt);
                        }


                        if (cb > 1)
                        {
                            char[] cfmt;
                            cfmt = fmt.ToCharArray();
                            for (a = 0; a < cfmt.Length; a++)
                            {
                                if (cfmt[a] == ' ' && cfmt[a + 1] == ')')
                                {
                                    cfmt[a] = ')';
                                    cfmt[a + 1] = ' ';
                                }
                            }
                            fmt = new string(cfmt);
                        }
                    }
                }


                return fmt;

            }


            try
            {
                M_main = Convert.ToDecimal(value);
            }
            catch (Exception ex) 
            {
                return "";
            }


            if (fmt.IndexOf('.') >= 0)
            {
                string lbuff;
                int pos_dot;
                pos_dot = fmt.IndexOf('.');
                lbuff = fmt.Substring(pos_dot + 1);
                fm1 = fmt.Substring(0, pos_dot);
                lbuff.TrimStart(' ');
                num_places = lbuff.Length;
                fm2 = lbuff;
            }
            else
            {
                fm1 = fmt;
                fm2 = "";
                num_places = 0;
            }


            Decimal n = Decimal.Parse(value);
            Decimal.Round(n, num_places, MidpointRounding.AwayFromZero);
            Decimal intPart = Decimal.Truncate(n);
            Decimal justDecPart = n - intPart;

            buff_decimal = justDecPart.ToString();
            buff_integer = intPart.ToString();
            // should always start "0."
            if (buff_decimal == "0")
            {
                buff_decimal = "0.0";
            }

            buff_decimal = buff_decimal.Substring(2);
            buff_integer=buff_integer.PadLeft(31);


            if (num_places > 64 || buff_decimal.Length >= 64)
            {

                // Its too big...

                return overflow;
            }
            buff_decimal = buff_decimal + "000000000000000000000000000000000";

            buff_decimal = buff_decimal.Substring(0, 32);

            str = fmt.ToCharArray();
            variable_called_b = 30;
            isprnt = true;

            // first, ensure the format string is wide enough to hold the number
            // if not, try drop trailing decimals, otherwise flag overflow with *'s
            {
                int f_cnt = 0;              // number of digits to left of dec. point in format
                int d_cnt = 0;              // number of digits to right of dec. point
                int n_cnt;
                if (isneg)
                {
                    n_cnt = 1;          // number of left-digits needed for number supplied
                }
                else
                {
                    n_cnt = 0;
                }

                if (isneg)
                {
                    if (fmt.Contains("(") || fmt.Contains(")") || fmt.Contains("+") || fmt.Contains("-"))
                    {

                    }
                    else
                    {
                        // No negative bit to display :-)
                        // so - we dont need to allow extra space for it...
                        n_cnt = 0;
                    }
                }
                else
                {
                    if (fmt.Contains("(") || fmt.Contains(")") || fmt.Contains("+") || fmt.Contains("-"))
                    {
                        bool compatfmt = true;
                        if (compatfmt)
                        {
                            n_cnt = 1;
                        }
                    }
                }


                // count format string number place holders, up to decimal point
                for (a = 0; a < fmt.Length; a++)
                {
                    if (fmt[a] == '.')
                        break;
                    if (CHAR_INDEX(rep_digit, fmt[a])!=-1)
                        f_cnt++;
                }
                // count format string number place holders, after the decimal point
                while (a < fmt.Length)
                {
                    if (CHAR_INDEX(rep_digit, fmt[a])!=-1)
                        d_cnt++;
                    a++;
                }
                // count the digits in the integer part of the number
                for (a = variable_called_b; (a > 0 && buff_integer[a] != ' '); a--)
                    n_cnt++;


                if (CHAR_INDEX(fmt, '$')!=-1) has_money = true;
                else has_money = false;

                if (f_cnt < n_cnt + (has_money?1:0))
                {
                    a = fmt.Length;
                    if (a > s)
                        a = s;


                    if (n_cnt > a)
                    {
                        // no way this number can fit, fill with stars ...

                        return overflow;
                    }


                    // default is to use the strict I4GL behaviour, stars

                    return overflow;
                }
            }

            for (a = (fm1.Length) - 1; a >= 0; a--)
            {
                if (CHAR_INDEX(rep_digit, fm1[a])!=-1)
                {
                    if (variable_called_b >= 0)
                    {
                        if (((buff_integer[variable_called_b] == '0' && buff_integer[variable_called_b - 1] == ' ') || buff_integer[variable_called_b] == ' ') && isprnt) isprnt = false;
                    }
                    str[a] = buff_integer[variable_called_b--];
                    if (!isprnt)
                    {
                        if (fm1[a] == '#')
                        {
                            str[a] = ' ';
                            continue;
                        }
                        if (fm1[a] == '*')
                        {
                            str[a] = '*';
                            continue;
                        }
                        if (fm1[a] == '&')
                        {
                            str[a] = '0';
                            continue;
                        }
                        if (fm1[a] == '<')
                        {
                            str[a] = '<';
                            continue;
                        }

                        p = CHAR_INDEX(canfloat_head, fm1[a]);

                        if (p >= 0)
                        {
                            canfloat_head[p] = (char)1;

                            if (fm1[a] == '+' && isneg)
                            {
                                str[a] = '-';
                                continue;
                            }
                            if (fm1[a] == '+' && !isneg)
                            {
                                str[a] = '+';
                                continue;
                            }
                            if (fm1[a] == '-' && isneg)
                            {
                                str[a] = '-';
                                continue;
                            }
                            if (fm1[a] == '-' && !isneg)
                            {
                                str[a] = ' ';
                                continue;
                            }
                            if (fm1[a] == '(')
                            {
                                if (isneg)
                                {
                                    str[a] = '(';
                                    continue;
                                }
                                else
                                {
                                    str[a] = ' ';
                                    continue;
                                }
                            }
                            if (fm1[a] == ')' && isneg)
                            {
                                str[a] = ')';
                                continue;
                            }
                            str[a] = fm1[a];
                            continue;
                        }
                        else
                        {
                            str[a] = ' ';
                            continue;
                        }
                        //str[a] = fm1[a];
                    }
                }
                else
                {
                    if (buff_integer[variable_called_b] == ' ' && str[a] == ',')
                    {
                        if (fm1[a + 1] == '<')
                        {
                            str[a] = '<';
                        }
                        else
                        {
                            str[a] = (char)0x01;
                        }
                    }
                }
            }
            variable_called_b = 0;


            for (a = 0; a < (fm2.Length); a++)
            {
                if (CHAR_INDEX(rep_digit, fm2[a])!=-1)
                {
                    if (fm2[a] == ')')
                    {
                        if (isneg)
                        {
                            str[a + (fm1.Length) + 1] = ')';
                            continue;
                        }
                        else
                        {
                            str[a + (fm1.Length) + 1] = ' ';
                            continue;
                        }
                    }
                    str[a + (int)(fm1.Length) + 1] = buff_decimal[variable_called_b++];
                }
                else
                {
                    str[a + (int)(fm1.Length) + 1] = fm2[a];
                }
            }

            //ptr = (string ) strrchr (str, '<');

            // for any unused leading "<" or "-<" format chars,
            // shift the output to the left
            str_as_string = new string(str);
            if (str_as_string.Contains("<"))
            {
                string buffx="";
                variable_called_b = 0;
                for (a = 0; a < (str.Length); a++)
                {
                    if (str[a] == '<')
                    {
                        if (str[a + 1] == ',')
                            str[a + 1] = '<';
                        continue;
                    }
                    if (!isneg && str[a] == '-' && str[a + 1] == '<')
                        continue;
                    buffx+= str[a];
                }
                
                str= buffx.ToCharArray();
            }

            for (a = 0; a < (str.Length); a++)
            {
                if (str[a] == 0x01)
                {

                    if (a == 0) str[a] = ' ';
                    else str[a] = str[a - 1];


                    if (a == 1)
                    {
                        if (str[a - 1] == '$') { str[a - 1] = ' '; }
                        if (str[a - 1] == '-') { str[a - 1] = ' '; }
                        if (str[a - 1] == '(') { str[a - 1] = ' '; }
                    }

                    if (a >= 2)
                    {
                        if (str[a - 1] == '$' && str[a - 2] != '$') { str[a - 1] = ' '; }
                        if (str[a - 1] == '-' && str[a - 2] != '-') { str[a - 1] = ' '; }
                        if (str[a - 1] == '(' && str[a - 2] != '(') { str[a - 1] = ' '; }
                    }
                }
            }


            for (a = (str.Length) - 1; a >= 0; --a)
            {
                if (str[a] == '.')
                {
                    str[a] = FGLUtils.a4gl_convfmts_ui_decfmt_decsep;
                }
                else
                {
                    if (str[a] == FGLUtils.a4gl_convfmts_ui_decfmt_decsep)
                    {
                        str[a] = FGLUtils.a4gl_convfmts_ui_decfmt_thsep;
                    }
                }
            }

            str_as_string = new string(str);
            if (has_money && !(str_as_string.Contains("$")))
            {
                int first_non_space = -1;
                // Lacking money!
                for (a = 0; a < (str.Length); a++)
                {
                    if (str[a] != ' ')
                    {
                        first_non_space = a;
                        break;
                    }
                }
                if (first_non_space > 0)
                {
                    if (str[first_non_space] == '-' || str[first_non_space] == '(' || str[first_non_space] == '+')
                    {
                        str[first_non_space - 1] = str[first_non_space];
                        str[first_non_space] = '$';
                    }
                    else
                    {
                        str[first_non_space - 1] = '$';
                    }
                }
            }
            
            
            return new string(str);
        }

        private static int CHAR_INDEX(string fmt, char p)
        {
            return CHAR_INDEX(fmt.ToCharArray(), p);
        }

        private static int CHAR_INDEX(char[] rep_digit, char p)
        {
            for (int a = 0; a < rep_digit.Length; a++)
            {
                if (rep_digit[a] == p) return a;
            }
            return -1;
        }



        private static string a4gl_using_date(string fmt, string value)
        {
            DateTime d;
            
            // Value should always be in DBDATE format..
            d = FGLUtils.getDate(value);
            fmt = fmt.Replace("mmmm", "MMMM");
            fmt = fmt.Replace("mmm", "MMM");
            fmt = fmt.Replace("mm", "MMM");
            return d.ToString(fmt);
            /*
            fmt = fmt.Replace("dddd", d.ToString("dddd"));
            fmt = fmt.Replace("ddd", d.ToString("ddd"));
            fmt = fmt.Replace("dd", d.ToString("dd"));
            fmt = fmt.Replace("mmmm", d.ToString("MMMM"));
            fmt = fmt.Replace("mmm", d.ToString("MMM"));
            fmt = fmt.Replace("mm", d.ToString("MM"));
            fmt = fmt.Replace("yyyy", d.ToString("yyyy"));
            fmt = fmt.Replace("yy", d.ToString("yy"));

            fmt = fmt.Replace("DDDD", d.ToString("dddd"));
            fmt = fmt.Replace("DDD", d.ToString("ddd"));
            fmt = fmt.Replace("DD", d.ToString("dd"));
            fmt = fmt.Replace("MMMM", d.ToString("MMMM"));
            fmt = fmt.Replace("MMM", d.ToString("MMM"));
            fmt = fmt.Replace("MM", d.ToString("MM"));
            fmt = fmt.Replace("YYYY", d.ToString("yyyy"));
            fmt = fmt.Replace("YY", d.ToString("yy"));

            return d.ToString(fmt);
             * */
        }


        private static string a4gl_using(string fmt, string value)
        {
            decimal d;
            bool isneg = false;
            if (value == "")
            {
                return "";
            }
            d = Convert.ToDecimal(value);
            if (d < 0)
            {
                d = 0 - d;
                isneg = true;
            }
            return a4gl_using_from_string(fmt, d.ToString(), isneg);
        }
    }
}
