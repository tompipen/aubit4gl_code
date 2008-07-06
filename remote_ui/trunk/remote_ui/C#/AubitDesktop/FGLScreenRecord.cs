using System;
using System.Collections.Generic;
using System.Windows.Forms;

using System.Text;

namespace AubitDesktop2
{
    class FGLScreenRecord
    {
        public string name;
        int dim;
        List<FGLScreenRecordAttributes> Attributes;

        public FGLScreenRecord(string Name, int dim)
        {
            //FGLScreenRecordAttributes z;
            this.name = Name;
            this.dim = dim;
            Attributes = new List<FGLScreenRecordAttributes>();
        }

        public void AddAttribute(ATTRIBUTE a)
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
