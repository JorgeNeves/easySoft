using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Collections.Specialized;
using System.Net;
using System.Text;
using System.IO;

namespace WebApplication5.Account
{
    public class oAuthFacebook
    {
        public enum Method { GET, POST };
        public const string AUTHORIZE = "https://graph.facebook.com/oauth/authorize";
        public const string ACCESS_TOKEN = "https://graph.facebook.com/oauth/access_token";
        public const string CALLBACK_URL = "http://localhost:24966/Account/facebookcallback.aspx";

        private string _consumerKey = "";
        private string _consumerSecret = "";
        private string _token = "";

        #region Properties

        public string ConsumerKey
        {
            get
            {
                if (_consumerKey.Length == 0)
                {
                    _consumerKey = "372268469524561"; //Your application ID
                }
                return _consumerKey;
            }
            set { _consumerKey = value; }
        }

        public string ConsumerSecret
        {
            get
            {
                if (_consumerSecret.Length == 0)
                {
                    _consumerSecret = "229cbddac2d0c3f316d58b0de2078ed3"; //Your application secret
                }
                return _consumerSecret;
            }
            set { _consumerSecret = value; }
        }

        public string Token { get { return _token; } set { _token = value; } }

        #endregion

        /// <summary>
        /// Get the link to Facebook's authorization page for this application.
        /// </summary>
        /// <returns>The url with a valid request token, or a null string.</returns>
        public string AuthorizationLinkGet()
        {
            return string.Format("{0}?client_id={1}&redirect_uri={2}", AUTHORIZE, this.ConsumerKey, CALLBACK_URL);
        }

        /// <summary>
        /// Exchange the Facebook "code" for an access token.
        /// </summary>
        /// <param name="authToken">The oauth_token or "code" is supplied by Facebook's authorization page following the callback.</param>
        public void AccessTokenGet(string authToken)
        {
            this.Token = authToken;
            string accessTokenUrl = string.Format("{0}?client_id={1}&redirect_uri={2}&client_secret={3}&code={4}",
            ACCESS_TOKEN, this.ConsumerKey, CALLBACK_URL, this.ConsumerSecret, authToken);

            string response = WebRequest(Method.GET, accessTokenUrl, String.Empty);

            if (response.Length > 0)
            {
                //Store the returned access_token
                NameValueCollection qs = HttpUtility.ParseQueryString(response);

                if (qs["access_token"] != null)
                {
                    this.Token = qs["access_token"];
                }
            }
        }

        /// <summary>
        /// Web Request Wrapper
        /// </summary>
        /// <param name="method">Http Method</param>
        /// <param name="url">Full url to the web resource</param>
        /// <param name="postData">Data to post in querystring format</param>
        /// <returns>The web server response.</returns>
        public string WebRequest(Method method, string url, string postData)
        {

            HttpWebRequest webRequest = null;
            StreamWriter requestWriter = null;
            string responseData = "";

            webRequest = System.Net.WebRequest.Create(url) as HttpWebRequest;
            webRequest.Method = method.ToString();
            webRequest.ServicePoint.Expect100Continue = false;
            webRequest.UserAgent = "LAPR5/2.0";
            webRequest.Timeout = 20000;
           

            if (method == Method.POST)
            {
                webRequest.ContentType = "application/x-www-form-urlencoded";

                //POST the data.
                requestWriter = new StreamWriter(webRequest.GetRequestStream());

                try
                {
                    requestWriter.Write(postData);
                }
                catch
                {
                    throw;
                }

                finally
                {
                    requestWriter.Close();
                    requestWriter = null;
                }
            }

            responseData = WebResponseGet(webRequest);
            webRequest = null;
            
            return responseData;
        }

        /// <summary>
        /// Process the web response.
        /// </summary>
        /// <param name="webRequest">The request object.</param>
        /// <returns>The response data.</returns>
        public string WebResponseGet(HttpWebRequest webRequest)
        {
            StreamReader responseReader = null;
            string responseData = "";

            try
            {
                responseReader = new StreamReader(webRequest.GetResponse().GetResponseStream());

                responseData = responseReader.ReadToEnd();
            }
            catch
            {
                throw;
            }
            finally
            {
                webRequest.GetResponse().GetResponseStream().Close();
                responseReader.Close();
                responseReader = null;
            }

            return responseData;
        }

        public string convert(string str)
        {
            string strInput = str;
            strInput = strInput.Replace("\\u00c0", "À");
            strInput = strInput.Replace("\\u00c1", "Á");
            strInput = strInput.Replace("\\u00c2", "Â");
            strInput = strInput.Replace("\\u00c3", "Ã");
            strInput = strInput.Replace("\\u00c4", "Ä");
            strInput = strInput.Replace("\\u00c5", "Å");
            strInput = strInput.Replace("\\u00c6", "Æ");
            strInput = strInput.Replace("\\u00c7", "Ç");
            strInput = strInput.Replace("\\u00c8", "È");
            strInput = strInput.Replace("\\u00c9", "É");
            strInput = strInput.Replace("\\u00ca", "Ê");
            strInput = strInput.Replace("\\u00cb", "Ë");
            strInput = strInput.Replace("\\u00cc", "Ì");
            strInput = strInput.Replace("\\u00cd", "Í");
            strInput = strInput.Replace("\\u00ce", "Î");
            strInput = strInput.Replace("\\u00cf", "Ï");
            strInput = strInput.Replace("\\u00d1", "Ñ");
            strInput = strInput.Replace("\\u00d2", "Ò");
            strInput = strInput.Replace("\\u00d3", "Ó");
            strInput = strInput.Replace("\\u00d4", "Ô");
            strInput = strInput.Replace("\\u00d5", "Õ");
            strInput = strInput.Replace("\\u00d6", "Ö");
            strInput = strInput.Replace("\\u00d8", "Ø");
            strInput = strInput.Replace("\\u00d9", "Ù");
            strInput = strInput.Replace("\\u00da", "Ú");
            strInput = strInput.Replace("\\u00db", "Û");
            strInput = strInput.Replace("\\u00dc", "Ü");
            strInput = strInput.Replace("\\u00dd", "Ý");

        
            strInput = strInput.Replace("\\u00df", "ß");
            strInput = strInput.Replace("\\u00e0", "à");
            strInput = strInput.Replace("\\u00e1", "á");
            strInput = strInput.Replace("\\u00e2", "â");
            strInput = strInput.Replace("\\u00e3", "ã");
            strInput = strInput.Replace("\\u00e4", "ä");
            strInput = strInput.Replace("\\u00e5", "å");
            strInput = strInput.Replace("\\u00e6", "æ");
            strInput = strInput.Replace("\\u00e7", "ç");
            strInput = strInput.Replace("\\u00e8", "è");
            strInput = strInput.Replace("\\u00e9", "é");
            strInput = strInput.Replace("\\u00ea", "ê");
            strInput = strInput.Replace("\\u00eb", "ë");
            strInput = strInput.Replace("\\u00ec", "ì");
            strInput = strInput.Replace("\\u00ed", "í");
            strInput = strInput.Replace("\\u00ee", "î");
            strInput = strInput.Replace("\\u00ef", "ï");
            strInput = strInput.Replace("\\u00f0", "ð");
            strInput = strInput.Replace("\\u00f1", "ñ");
            strInput = strInput.Replace("\\u00f2", "ò");
            strInput = strInput.Replace("\\u00f3", "ó");
            strInput = strInput.Replace("\\u00f4", "ô");
            strInput = strInput.Replace("\\u00f5", "õ");
            strInput = strInput.Replace("\\u00f6", "ö");
            strInput = strInput.Replace("\\u00f8", "ø");
            strInput = strInput.Replace("\\u00f9", "ù");
            strInput = strInput.Replace("\\u00fa", "ú");
            strInput = strInput.Replace("\\u00fb", "û");
            strInput = strInput.Replace("\\u00fc", "ü");
            strInput = strInput.Replace("\\u00fd", "ý");
            strInput = strInput.Replace("\\u00ff", "ÿ");
        return strInput;
        }
    }
}