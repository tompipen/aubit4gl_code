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
using System.Windows.Forms;

using System.Text;

namespace AubitDesktop
{
    public class FGLScreenRecord
    {
        public string name;
        private int dim;
        private List<FGLScreenRecordAttributes> Attributes;

        public FGLScreenRecord(string Name, int dim)
        {
            //FGLScreenRecordAttributes z;
            this.name = Name;
            this.dim = dim;
            Attributes = new List<FGLScreenRecordAttributes>();
        }

        public FGLScreenRecord(string Name)
        {
            //FGLScreenRecordAttributes z;
            this.name = Name;
            this.dim = 1;
            Attributes = new List<FGLScreenRecordAttributes>();
        }

        public void AddAttribute(ATTRIBUTE a)
        {
            Attributes.Add(new FGLScreenRecordAttributes(a));
        }

        public void AddAttribute(AubitDesktop.Xml.XMLForm.Link a)
        {
            Attributes.Add(new FGLScreenRecordAttributes(a));
        }

        public List<int> AttributeNoList()
        {
            List<int> n;
            n = new List<int>();
            foreach (FGLScreenRecordAttributes a in Attributes)
            {
                if (!n.Contains(a.AttributeNo))
                {
                    n.Add(a.AttributeNo);
                }
            }
            return n;
        }
        public int FindAttributeNo(string Name)
        {
            foreach (FGLScreenRecordAttributes a in Attributes)
            {
                if (a.Name == Name) return a.AttributeNo;
            }
            MessageBox.Show("Field " + Name + " was not found");
            return -1;
        }
    }
}
