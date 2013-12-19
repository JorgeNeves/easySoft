using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace MvcApplication1.Models
{
    public class Tag
    {

        public int TagID { get; set; }
        public int TagOriginalID { get; set; }
        public string Palavra { get; set; }
    }
}