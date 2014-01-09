using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Security.Cryptography;
using System.Text;


namespace SocialiteWebService
{
    namespace EncryptionHelpers
    {
        public class MD5
        {
            public static string GetHash(string password)
            {
                byte[] encoded = 
                    new MD5CryptoServiceProvider().ComputeHash(
                    new UTF8Encoding().GetBytes(password));

                string hashed = "";
                foreach (byte b in encoded)
                {
                    hashed += b.ToString("x2");
                }
                return hashed;
            }
        }
    }
   
}