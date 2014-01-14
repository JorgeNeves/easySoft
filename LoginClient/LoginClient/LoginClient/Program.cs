using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;

namespace LoginClient
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            string datadir = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\";
            datadir += ConfigurationManager.AppSettings["DataDir"];

            bool isExists = System.IO.Directory.Exists(datadir);

            if (!isExists)
                System.IO.Directory.CreateDirectory(datadir);

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new LoginForm());
        }
    }
}
