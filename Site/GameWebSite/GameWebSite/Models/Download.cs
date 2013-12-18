using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace GameWebSite.Models
{
    public class Download
    {
        
        private int DownloadID { get; set; }
        private DateTime Data { get; set; }
        private int UserID { get; set; }
    }
}