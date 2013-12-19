using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace MvcApplication1.Models
{
    public class Download
    {
        
        public int DownloadID { get; set; }
        public DateTime Data { get; set; }
        public int UserID { get; set; }
    }
}