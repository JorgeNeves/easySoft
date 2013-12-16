using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace GameWebSite.Models
{
    public class TagOriginal
    {
        [Key]
        public string TagOriginalID { get; set; }
        public string PalavraOriginal { get; set; }
    }
}