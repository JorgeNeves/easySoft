using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace GameWebSite.Models
{
    public class Estado_Humor
    {
        [Key]
        private string Estado_HumorID { get; set; }
        private string Sentimento { get; set; }
    }
}