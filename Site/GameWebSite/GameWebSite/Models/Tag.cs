using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace GameWebSite.Models
{
    public class Tag
    {
        
        private int TagID { get; set; }
        private int TagOriginalID { get; set; }
        private string Palavra { get; set; }
    }
}