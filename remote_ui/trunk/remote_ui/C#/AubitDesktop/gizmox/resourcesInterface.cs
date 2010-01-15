using System;
using System.Collections.Generic;
using System.Text;

namespace AubitDesktop
{
    class resourceInterface
    {
        static System.Resources.ResourceManager rm = null;
        public static object getObject(string name)
        {
            object obj = null;

            if (rm == null) rm = new System.Resources.ResourceManager("AubitDesktop.Properties.Resources", typeof(AubitDesktop.Properties.Settings).Assembly);
            try
            {
                obj = rm.GetObject(name);
            }
            catch (Exception )
            {
                obj = null;
            }
            return obj;
        }
    }
}
