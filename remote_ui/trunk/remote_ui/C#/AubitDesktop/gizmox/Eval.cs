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
using Microsoft.CSharp;
using  System.CodeDom.Compiler;
using System.Reflection;
using System.IO;
using System.Diagnostics;


namespace AubitDesktop
{
    class Eval
    {

        private CompilerErrorCollection m_oCompilerErrors;
        public CompilerErrorCollection CompilerErrors
        {
            get
            {
                return m_oCompilerErrors;
            }
            set
            {
                m_oCompilerErrors = value;
            }
        }
        private CompilerResults oCResults;
        private object _oRetObj = null;
       

        public object returnedObject
        {
            get
            {
                return _oRetObj;
            }
        }

        public Eval()
        {
            oCResults = null;

        }

        public Eval(string code)
        {
            Compile(code);
            Execute();
        }

        public void Compile(string code) {
            char[] crlf={'\r','\n'};
            string nl = new string(crlf);
            CSharpCodeProvider oCodeProvider = new CSharpCodeProvider();
            m_oCompilerErrors = new CompilerErrorCollection();
            CompilerParameters oCParams = new CompilerParameters();

            oCResults = null;
            
            
            
            if (code == null) code = "Program.Show(\"Hello World\");";
            oCParams.ReferencedAssemblies.Add("system.dll");
            oCParams.ReferencedAssemblies.Add("system.xml.dll");
            oCParams.ReferencedAssemblies.Add("system.data.dll");
            oCParams.ReferencedAssemblies.Add("system.windows.forms.dll");
            oCParams.CompilerOptions = "/t:library";
            oCParams.GenerateInMemory = true;

            string s = "using Gizmox.WebGUI.Forms;" + nl +
                        "namespace AubitDesktop{" + nl +
                        " class EvalRunTime {" + nl +
                        "  public object EvaluateIt() {" + nl +
                        code +nl +
                        "return null;" + nl +
                        "  }" + nl +
                        " }" + nl +
                        "}";

            
            oCResults = oCodeProvider.CompileAssemblyFromSource(oCParams, s);
            if (oCResults.Errors.Count != 0)
            {
                this.CompilerErrors = oCResults.Errors;

            }
            else
            {
                this.CompilerErrors = null;
            }
        }

        public void Execute() {
            object oExecInstance = null;
            System.Reflection.Assembly oAssy;
            MethodInfo oMethodInfo;
            Type oType;

            _oRetObj = null;
            if (this.CompilerErrors != null) return;
            if (oCResults == null) return;

                oAssy = oCResults.CompiledAssembly;
                oExecInstance = oAssy.CreateInstance("AubitDesktop.EvalRunTime");
                if (oExecInstance == null)
                {
                   Program.Show("Unable to locate function");
                }
                else
                {

                    oType = oExecInstance.GetType();
                    oMethodInfo = oType.GetMethod("EvaluateIt");


                    _oRetObj = oMethodInfo.Invoke(oExecInstance, null);
                }
                 return;
            
        }
    }
}

            
            


